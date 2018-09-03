let component = ReasonReact.statelessComponent("Days");

type dayName =
  | Sun
  | Mon
  | Tue
  | Wed
  | Thu
  | Fri
  | Sat;

let dayStyle = (~frontColor as f="white", ~backColor as b="#4fc3f7", ()) =>
  ReactDOMRe.Style.make(
    ~margin="2px",
    ~padding="0.5em",
    ~background=b,
    ~color=f,
    (),
  );

let dayEle = (i, day: string) => {
  let style =
    day === "Sun" || day === "Sat" ?
      dayStyle(~backColor="#80deea", ~frontColor="black", ()) : dayStyle();

  <div className="col-sm card" style key=("day-header-" ++ string_of_int(i))>
    (ReasonReact.string(day))
  </div>;
};

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

let dayList =
  [|Sun, Mon, Tue, Wed, Thu, Fri, Sat|]
  |> Array.map(dayText)
  |> Array.mapi(dayEle)
  |> ReasonReact.array;

let make = _children => {
  ...component,
  render: _ =>
    <div className="container"> <div className="row"> dayList </div> </div>,
};

[@bs.deriving abstract]
type jsProps = {
  children: array(ReasonReact.reactElement),
};

let jsComponent =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      jsProps->childrenGet,
    )
  );