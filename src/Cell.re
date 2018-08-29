let component = ReasonReact.statelessComponent("Cell");

let getStyle =
    ((currentMonth, day: DayUtil.day, selectedDate: option(DayUtil.day))) => {
  let selected =
    switch (selectedDate) {
    | None => "0-0-0"
    | Some(day) => day.str
    };

  let backgroundColor =
    selected === day.str ?
      "#ffeb3b" : currentMonth === day.month ? "#bbdefb" : "#e0e0e0";

  ReactDOMRe.Style.make(
    ~margin="2px",
    ~padding="0.5em",
    ~backgroundColor,
    (),
  );
};

let make =
    (~day: DayUtil.day, ~select, ~currentMonth, ~selectedDate, _children) => {
  ...component,
  render: _self =>
    <div
      className="col-sm card cell"
      style=((currentMonth, day, selectedDate) |> getStyle)
      onClick=(_evt => select(day))>
      (ReasonReact.string(day.date |> string_of_int))
    </div>,
};