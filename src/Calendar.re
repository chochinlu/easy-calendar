let component = ReasonReact.statelessComponent("Calendar");

let make = _children => {
  ...component,
  render: _ =>
    <div className="bordered responsive-margin">
      <Header />
      <Days />
      <Cells />
    </div>,
};