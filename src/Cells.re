/* date-fns startOfweek, endOfWeek */
[@bs.module "date-fns"] external startOfWeek : string => Js.Date.t = "";

let component = ReasonReact.statelessComponent("Cells");

let cellEle = (_: string) =>
  <div className="col-sm card"> (ReasonReact.string("day")) </div>;

let cellEleRow = "" |> cellEle |> ArrayLabels.make(7);

let renderDays = () => {
  Js.log("render days");
  let someTest = 2018 |> string_of_int |> startOfWeek |> DayUtil.dayInfo;
  Js.log(someTest);
};

let make = (~currentMonth, _children) => {
  ...component,
  render: _ =>
    <div className="container">
      <div className="row"> ...cellEleRow </div>
      <div className="row"> ...cellEleRow </div>
      <div className="row"> ...cellEleRow </div>
      <div className="row"> ...cellEleRow </div>
      <div className="row"> ...cellEleRow </div>
      <button onClick=(_e => renderDays())>
        (
          currentMonth
          |> string_of_int
          |> (e => "current month: " ++ e |> ReasonReact.string)
        )
      </button>
    </div>,
};