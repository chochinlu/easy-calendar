let component = ReasonReact.statelessComponent("Calendar");

let make = (_children) => {
  ...component,
  render: _ => 
    <div className="bordered responsive-margin">
      <h2>(ReasonReact.string("Header"))</h2>
      <h2>(ReasonReact.string("Days"))</h2>
      <h2>(ReasonReact.string("Cell"))</h2>
    </div>,
};