module Router = {
  type t;
  external init: t => unit = "init" [@@bs.send];
  external mkRouter: Js.Dict.t ('a => unit) => t = "Router" [@@bs.module "director"];
  let make routes =>
    mkRouter (Utils.mkDict routes);
};
