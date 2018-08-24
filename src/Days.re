let component = ReasonReact.statelessComponent("Days");

type dayName =
  | Sun
  | Mon
  | Tue
  | Wed
  | Thu
  | Fri
  | Sat;

let dayText = (day: dayName) : string =>
  switch (day) {
  | Sun => "Sun"
  | Mon => "Mon"
  | Tue => "Tue"
  | Wed => "Wed"
  | Thu => "Thu"
  | Fri => "Fri"
  | Sat => "Sat"
  };

let dayEle = day => <div className="col-sm card"> (ReasonReact.string(day)) </div>;

let dayList =
  [|Sun, Mon, Tue, Wed, Thu, Fri, Sat|]
  |> Array.map(dayText)
  |> Array.map(dayEle)
  |> ReasonReact.array;

let make = _children => {
  ...component,
  render: _ =>
    <div className="container">
      <div className="row">(dayList)</div>
    </div>,
};