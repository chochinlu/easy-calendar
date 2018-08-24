let component = ReasonReact.statelessComponent("Cells");

let cellEle = (_: string) =>
  <div className="col-sm card"> (ReasonReact.string("day")) </div>;

let cellEleRow = "" |> cellEle |> ArrayLabels.make(7) |> ReasonReact.array;
let cells = "" |> ArrayLabels.make(5);

let make = _children => {
  ...component,
  render: _ =>
    <div className="container">
      <div className="row"> cellEleRow </div>
      <div className="row"> cellEleRow </div>
      <div className="row"> cellEleRow </div>
      <div className="row"> cellEleRow </div>
    </div>,
};