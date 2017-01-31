type item = {
  id: string,
  title: string,
  completed: bool
};

module NodoItem = {
  include ReactRe.Component;
  let name = "NodoItem";

  type props = {
    item: item,
    onToggle: ReactRe.event => unit,
    onDestroy: ReactRe.event => unit,
  };

  let render {props, updater} => {
    let editing = false;
    let className =
      [props.item.completed ? "completed" : "", editing ? "editing" : ""] |> String.concat " ";

    <li className>
      <div className="view">
        <input
          type_="checkbox"
          className="toggle"
          checked=(Js.Boolean.to_js_boolean props.item.completed)
          onChange=props.onToggle />
        <label> (ReactRe.stringToElement props.item.title) </label>
        <button className="destroy" onClick=props.onDestroy />
      </div>
    </li>;
  }
};

include ReactRe.CreateComponent NodoItem;

let createElement ::item ::onToggle ::onDestroy ::children =>
  wrapProps { item, onToggle, onDestroy } ::children;
