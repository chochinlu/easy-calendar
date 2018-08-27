type day = {
  year: string,
  month: string,
  date: string,
  str: string,
};

let floatStr = str => str |> int_of_float |> string_of_int;

let dayInfo = (someDay: Js.Date.t) : day => {
  let year = someDay |> Js.Date.getUTCFullYear |> floatStr;
  let month = someDay |> (d => Js.Date.getUTCMonth(d) +. 1.0) |> floatStr;
  let date = someDay |> Js.Date.getUTCDate |> floatStr;
  let dayStr = year ++ "-" ++ month ++ "-" ++ date;

  {year, month, date, str: dayStr};
};

let today = Js.Date.make() |> dayInfo;

type state = {show: bool};

type action =
  | Show;

let component = ReasonReact.reducerComponent("Calendar");

let make = _children => {
  ...component,
  initialState: () => {show: false},
  reducer: (action, state) =>
    switch (action) {
    | Show => ReasonReact.Update({show: ! state.show})
    },
  render: self =>
    <div className="bordered responsive-margin">
      <Header
        today=today.str
        handleShow=(_evt => self.send(Show))
        show=self.state.show
      />
      <Days />
      <Cells />
    </div>,
};