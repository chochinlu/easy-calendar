/* date-fns startOfweek, endOfWeek */
[@bs.module "date-fns"] external startOfWeek : string => Js.Date.t = "";
[@bs.module "date-fns"] external addDays : (Js.Date.t, int) => Js.Date.t = "";

let component = ReasonReact.statelessComponent("Cells");

/* cells mockup */
let cellEle = (_: string) =>
  <div className="col-sm card"> (ReasonReact.string("day")) </div>;

let cellEleRow = "" |> cellEle |> ArrayLabels.make(7);

/* render real days  */
let renderDays = (someYear: int, someMonth: int) => {
  let startDay =
    [|someYear, someMonth|]
    |> Array.map(string_of_int)
    |> Array.fold_left((a, b) => a ++ "-" ++ b, "")
    |> startOfWeek;

  Js.log(startDay);

  let initDay: DayUtil.day = {year: 0, month: 0, date: 0, str: ""};

  let weekDaysArr =
    Array.make(7, initDay)
    |> Array.mapi((x, _) => addDays(startDay, x) |> DayUtil.dayInfo);

  Js.log(weekDaysArr);
};

let make = (~currentMonth, ~currentYear, _children) => {
  ...component,
  render: _ =>
    <div className="container">
      <div className="row"> ...cellEleRow </div>
      <button onClick=(_e => renderDays(currentYear, currentMonth))>
        (
          currentMonth
          |> string_of_int
          |> (e => "current month: " ++ e |> ReasonReact.string)
        )
      </button>
    </div>,
};