module NodoList = {
  include ReactRe.Component;
  let name = "NodoList";

  type props = {items: list NodoItem.item};

  let render {props, updater} =>
    <ul className="todo-list">
      (ReactRe.arrayToElement (Array.of_list (List.map (fun item => <NodoItem item=item onToggle=(fun e => ()) onDestroy=(fun e => ()) />) props.items)))
    </ul>;
};

include ReactRe.CreateComponent NodoList;

let createElement ::items ::children => wrapProps { items: items } ::children;
