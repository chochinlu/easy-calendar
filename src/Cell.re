let component = ReasonReact.statelessComponent("Cell");

let getStyle = ((currentMonth, dayMonth)) => {
  let backgroundColor = currentMonth === dayMonth ? "#bbdefb" : "#e0e0e0";
  ReactDOMRe.Style.make(
    ~margin="2px",
    ~padding="0.5em",
    ~backgroundColor,
    (),
  );
};

let make = (~day: DayUtil.day, ~select, ~currentMonth, _children) => {
  ...component,
  render: _self =>
    <div
      className="col-sm card cell"
      style=((currentMonth, day.month) |> getStyle)
      onClick=(_evt => select(day))>
      (ReasonReact.string(day.date |> string_of_int))
    </div>,
};