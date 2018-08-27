let component = ReasonReact.statelessComponent("Header");

let yearMonth = (year: int, month: int) : string =>
  (year |> string_of_int) ++ "-" ++ (month |> string_of_int);

let make =
    (
      ~today,
      ~handleShow,
      ~show,
      ~currentMonth,
      ~currentYear,
      ~clickPrev,
      ~clickNext,
      ~clickCurrent,
      _children,
    ) => {
  ...component,
  render: _self =>
    <div>
      <p> (today |> (t => {j|今日: |j} ++ t |> ReasonReact.string)) </p>
      <h2> (yearMonth(currentYear, currentMonth) |> ReasonReact.string) </h2>
      <button onClick=clickPrev>
        (ReasonReact.string({j|上個月|j}))
      </button>
      <button onClick=clickCurrent>
        (ReasonReact.string({j|這個月|j}))
      </button>
      <button onClick=clickNext>
        (ReasonReact.string({j|下個月|j}))
      </button>
      <button onClick=(_e => Js.log("oh"))>
        (ReasonReact.string("show console log"))
      </button>
      <button onClick=handleShow>
        (ReasonReact.string("show/hide msg"))
      </button>
      <h2> (show ? ReasonReact.string("hi") : ReasonReact.null) </h2>
    </div>,
};