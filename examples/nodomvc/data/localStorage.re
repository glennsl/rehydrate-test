let namespace = "nodomvc";

let get () =>
  Js.Null.to_opt (ReasonJs.LocalStorage.getItem namespace);

let set state =>
  ReasonJs.LocalStorage.setItem namespace (ReasonJs.JSON.stringify state);
