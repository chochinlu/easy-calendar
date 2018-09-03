[%%bs.raw {|
  require('./more.css');
|}];

let today = Js.Date.make() |> DayUtil.dayInfo;

type state = {
  show: bool,
  currentMonth: int,
  currentYear: int,
  selectedDate: option(DayUtil.day),
};

type action =
  | Show
  | PrevMonth
  | NextMonth
  | ThisMonth
  | SelectDate(DayUtil.day);

let component = ReasonReact.reducerComponent("Calendar");

let make = _children => {
  ...component,
  initialState: () => {
    show: false,
    currentMonth: today.month,
    currentYear: today.year,
    selectedDate: Some(today),
  },
  reducer: (action, state) =>
    switch (action) {
    | Show => ReasonReact.Update({...state, show: ! state.show})
    | PrevMonth =>
      let month = state.currentMonth - 1 |> (e => e < 1 ? 12 : e);
      let year =
        state.currentMonth
        - 1
        |> (e => e < 1 ? state.currentYear - 1 : state.currentYear);
      ReasonReact.Update({...state, currentMonth: month, currentYear: year});
    | NextMonth =>
      let month = state.currentMonth + 1 |> (e => e > 12 ? 1 : e);
      let year =
        state.currentMonth
        + 1
        |> (e => e > 12 ? state.currentYear + 1 : state.currentYear);
      ReasonReact.Update({...state, currentMonth: month, currentYear: year});
    | ThisMonth =>
      ReasonReact.Update({
        ...state,
        currentMonth: today.month,
        currentYear: today.year,
      })
    | SelectDate(day) =>
      ReasonReact.Update({...state, selectedDate: Some(day)})
    },
  render: ({state, send}) =>
    <div className="bordered responsive-margin">
      <HelloRe selectedDay=state.selectedDate todayStr=today.str />
      <Header
        todayStr=today.str
        show=state.show
        currentMonth=state.currentMonth
        currentYear=state.currentYear
        selectedDate=state.selectedDate
        handleShow=(_evt => send(Show))
        clickPrev=(_evt => send(PrevMonth))
        clickNext=(_evt => send(NextMonth))
        clickCurrent=(_evt => send(ThisMonth))
      />
      <Days />
      <Cells
        currentMonth=state.currentMonth
        currentYear=state.currentYear
        selectedDate=state.selectedDate
        select=(evt => send(SelectDate(evt)))
      />
    </div>,
};

[@bs.deriving abstract]
type jsProps = {
  children: array(ReasonReact.reactElement),
};

let jsComponent =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      jsProps->childrenGet,
    )
  );