let today = Js.Date.make() |> DayUtil.dayInfo;

type state = {
  show: bool,
  currentMonth: int,
  currentYear: int,
};

type action =
  | Show
  | PrevMonth
  | NextMonth
  | ThisMonth;

let component = ReasonReact.reducerComponent("Calendar");

let make = _children => {
  ...component,
  initialState: () => {
    show: false,
    currentMonth: today.month,
    currentYear: today.year,
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
    },
  render: self =>
    <div className="bordered responsive-margin">
      <Header
        today=today.str
        show=self.state.show
        currentMonth=self.state.currentMonth
        currentYear=self.state.currentYear
        handleShow=(_evt => self.send(Show))
        clickPrev=(_evt => self.send(PrevMonth))
        clickNext=(_evt => self.send(NextMonth))
        clickCurrent=(_evt => self.send(ThisMonth))
      />
      <Days />
      <Cells
        currentMonth=self.state.currentMonth
        currentYear=self.state.currentYear
      />
    </div>,
};