type day = {
  year: int,
  month: int,
  date: int,
  str: string,
};

let floatStr = str => str |> int_of_float |> string_of_int;

let getDayStr = (year, month, date) =>
  string_of_int(year)
  ++ "-"
  ++ string_of_int(month)
  ++ "-"
  ++ string_of_int(date);

let dayInfo = (someDay: Js.Date.t) : day => {
  let year = someDay |> Js.Date.getUTCFullYear |> int_of_float;
  let month = someDay |> (d => Js.Date.getUTCMonth(d) +. 1.0) |> int_of_float;
  let date = someDay |> Js.Date.getUTCDate |> int_of_float;
  let dayStr = getDayStr(year, month, date);

  {year, month, date, str: dayStr};
};

let today = Js.Date.make() |> dayInfo;

type state = {
  show: bool,
  currentMonth: int,
};

type action =
  | Show
  | PrevMonth
  | NextMonth
  | ThisMonth;

let component = ReasonReact.reducerComponent("Calendar");

let make = _children => {
  ...component,
  initialState: () => {show: false, currentMonth: today.month},
  reducer: (action, state) =>
    switch (action) {
    | Show => ReasonReact.Update({...state, show: ! state.show})
    | PrevMonth =>
      let month = state.currentMonth - 1 |> (e => e < 1 ? 1 : e);
      ReasonReact.Update({...state, currentMonth: month});
    | NextMonth =>
      let month = state.currentMonth + 1 |> (e => e > 12 ? 12 : e);
      ReasonReact.Update({...state, currentMonth: month});
    | ThisMonth => ReasonReact.Update({...state, currentMonth: today.month})
    },
  render: self =>
    <div className="bordered responsive-margin">
      <Header
        today=today.str
        show=self.state.show
        currentMonth=self.state.currentMonth
        handleShow=(_evt => self.send(Show))
        clickPrev=(_evt => self.send(PrevMonth))
        clickNext=(_evt => self.send(NextMonth))
        clickCurrent=(_evt => self.send(ThisMonth))
      />
      <Days />
      <Cells />
    </div>,
};