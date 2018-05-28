[@bs.deriving abstract]
type jsProps = {markers: array((float, float))};

[@bs.module "./BasicMap"]
external markerComponent : ReasonReact.reactClass = "BasicMap";
let make = (~markers, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=markerComponent,
    ~props=jsProps(~markers),
    children,
  );