let component = ReasonReact.statelessComponent("App");

let make = (~message, _children) => {
  ...component,
  render: _ => 
    <div>
      <h1>(ReasonReact.string(message))</h1>
      <Calendar />
    </div>,
};