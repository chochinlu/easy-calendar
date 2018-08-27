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

let component = ReasonReact.statelessComponent("Calendar");

let make = _children => {
  ...component,
  render: _ =>
    <div className="bordered responsive-margin">
      <Header today=today.str />
      <Days />
      <Cells />
    </div>,
};