/* date-fns startOfweek, endOfWeek */
[@bs.module "date-fns"] external startOfWeek : string => Js.Date.t = "";

let component = ReasonReact.statelessComponent("Cells");

/* cells mockup */
let cellEle = (_: string) =>
  <div className="col-sm card"> (ReasonReact.string("day")) </div>;

let cellEleRow = "" |> cellEle |> ArrayLabels.make(7);

/* render real days  */
let renderDays = (today: DayUtil.day) => {
  let year = today.year |> float_of_int |> string_of_float;
  let month = today.month |> float_of_int |> string_of_float;
  let someTest = year ++ month |> startOfWeek |> DayUtil.dayInfo;
  Js.log(someTest);
};

let make = (~currentMonth, ~today, _children) => {
  ...component,
  render: _ =>
    <div className="container">
      <div className="row"> ...cellEleRow </div>
      <div className="row"> ...cellEleRow </div>
      <div className="row"> ...cellEleRow </div>
      <div className="row"> ...cellEleRow </div>
      <div className="row"> ...cellEleRow </div>
      <button onClick=(_e => renderDays(today))>
        (
          currentMonth
          |> string_of_int
          |> (e => "current month: " ++ e |> ReasonReact.string)
        )
      </button>
    </div>,
};