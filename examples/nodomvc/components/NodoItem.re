module NodoItem = {
  include ReactRe.Component.Stateful;
  let name = "NodoItem";

  type props = {
    item: Todo.t,
    selected: bool,
    store: Store.t
  };
  type state = {
    editing: bool
  };

  let getInitialState props => {
    editing: false
  };

  let render {props, state, updater} => {
    let { item, selected, store } = props;
    let { editing } = state;
    let className = Utils.classNames [
      ("completed", item.completed),
      ("editing", editing),
      ("selected", selected)
    ];
    let save = updater (fun {state} text => {
      Store.update store item text;
      Some { editing: false }
    });
    let edit = updater (fun {state} e => Some { editing: true });
    let select e => Utils.gotoHash item.id;
    let toggle e => Store.toggle store item;
    let remove e => Store.remove store item;

    <li className>
      <div className="view">
        <input
          type_="checkbox"
          className="toggle"
          checked=(Js.Boolean.to_js_boolean item.completed)
          onChange=toggle
        />

        <label onDoubleClick=edit onClick=select>
          (ReactRe.stringToElement item.title)
        </label>

        <button className="destroy" onClick=remove />
      </div>

      (editing ?
        <NodoTextInput className="edit" onSave=save value=item.title /> :
        ReactRe.nullElement)

      <div className="created">
        <TimeAgo date=item.created />
      </div>
    </li>
  }
};

include ReactRe.CreateComponent NodoItem;
let createElement ::item ::selected ::store ::children =>
  wrapProps { item, selected, store } ::children;
