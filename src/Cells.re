/* date-fns startOfweek, endOfWeek */
[@bs.module "date-fns"] external startOfWeek : string => Js.Date.t = "";
[@bs.module "date-fns"] external addDays : (Js.Date.t, int) => Js.Date.t = "";

let component = ReasonReact.statelessComponent("Cells");

/* get every start date of week */
let firstStartDay = ((someYear: int, someMonth: int)) =>
  [|someYear, someMonth|]
  |> Array.map(string_of_int)
  |> Array.fold_left((a, b) => a ++ "-" ++ b, "")
  |> startOfWeek;

let getStartDays = (startDay: Js.Date.t) =>
  Array.make(5, startDay) |> Array.mapi((x, _) => addDays(startDay, 7 * x));

let getOneWeekDays = (startDay: Js.Date.t) => {
  let initDay: DayUtil.day = {year: 0, month: 0, date: 0, str: ""};
  Array.make(7, initDay)
  |> Array.mapi((x, _) => addDays(startDay, x) |> DayUtil.dayInfo);
};

let cellStyle = (~background as b="#bbdefb", ()) =>
  ReactDOMRe.Style.make(~margin="2px", ~padding="0.5em", ~background=b, ());

let renderWeekRow = (renderDays: array(DayUtil.day), currentMonth) =>
  renderDays
  |> Array.map((e: DayUtil.day) => {
       let style =
         currentMonth === e.month ?
           cellStyle() : cellStyle(~background="#e0e0e0", ());
       <div className="col-sm card" style>
         (ReasonReact.string(e.date |> string_of_int))
       </div>;
     });

let renderOneWeek = weekDays => <div className="row"> ...weekDays </div>;

let renderDays = ((someYear: int, someMonth: int), currentMonth) =>
  (someYear, someMonth)
  |> firstStartDay
  |> getStartDays
  |> Array.map(getOneWeekDays)
  |> Array.map(e => renderWeekRow(e, currentMonth))
  |> Array.map(renderOneWeek)
  |> ReasonReact.array;

let make = (~currentMonth, ~currentYear, _children) => {
  ...component,
  render: _ =>
    <div className="container">
      (renderDays((currentYear, currentMonth), currentMonth))
      <button
        onClick=(
          _e =>
            (currentYear, currentMonth)
            |> firstStartDay
            |> getStartDays
            |> Js.log
        )>
        (
          currentMonth
          |> string_of_int
          |> (e => "current month: " ++ e |> ReasonReact.string)
        )
      </button>
    </div>,
};