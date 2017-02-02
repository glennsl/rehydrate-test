type esModule 'a = Js.t {. default: 'a };
external timeAgo: esModule ReactRe.reactClass = "react-timeago" [@@bs.module];
/*external timeAgo: ReactRe.reactClass = "default" [@@bs.module "react-timeago"];*/

let createElement date::(date: ReasonJs.Date.t) =>
  ReactRe.wrapPropsShamelessly timeAgo##default { "date": date };
