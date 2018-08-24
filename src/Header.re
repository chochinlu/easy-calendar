let component = ReasonReact.statelessComponent("Header");

let make = _children => {
  ...component,
  render: _ =>
    <div>
      <h2> (ReasonReact.string({j|這個月|j})) </h2>
      <button> (ReasonReact.string({j|上個月|j})) </button>
      <button> (ReasonReact.string({j|下個月|j})) </button>
    </div>,
};