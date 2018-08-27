let component = ReasonReact.statelessComponent("Header");

let make = (~today, ~handleShow, ~show, _children) => {
  ...component,
  render: self =>
    <div>
      <p> (today |> (t => {j|今日: |j} ++ t |> ReasonReact.string)) </p>
      <h2> (ReasonReact.string({j|這個月|j})) </h2>
      <button> (ReasonReact.string({j|上個月|j})) </button>
      <button> (ReasonReact.string({j|下個月|j})) </button>
      <button onClick=(_e => Js.log("oh"))>
        (ReasonReact.string("show"))
      </button>
      <button onClick=handleShow> (ReasonReact.string("show2")) </button>
      <h2> (show ? ReasonReact.string("hi") : ReasonReact.null) </h2>
    </div>,
};