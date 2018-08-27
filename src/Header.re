let component = ReasonReact.statelessComponent("Header");

let make = (~today, _children) => {
  ...component,
  render: _ =>
    <div>
      <p> (today |> (t => {j|今日: |j} ++ t |> ReasonReact.string)) </p>
      <h2> (ReasonReact.string({j|這個月|j})) </h2>
      <button> (ReasonReact.string({j|上個月|j})) </button>
      <button> (ReasonReact.string({j|下個月|j})) </button>
    </div>,
};