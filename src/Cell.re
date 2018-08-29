let component = ReasonReact.statelessComponent("Cell");

let cellStyle = (~background as b="#bbdefb", ()) =>
  ReactDOMRe.Style.make(~margin="2px", ~padding="0.5em", ~background=b, ());

let make = (~day: DayUtil.day, ~select, ~currentMonth, _children) => {
  ...component,
  render: _self => {
    let style =
      currentMonth === day.month ?
        cellStyle() : cellStyle(~background="#e0e0e0", ());

    <div className="col-sm card cell" style onClick=(_evt => select(day))>
      (ReasonReact.string(day.date |> string_of_int))
    </div>;
  },
};