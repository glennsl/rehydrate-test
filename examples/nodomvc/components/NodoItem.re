type t = {
  id: string,
  title: string,
  completed: bool,
  created: ReasonJs.Date.t
};

module NodoItem = {
  include ReactRe.Component.Stateful;
  let name = "NodoItem";

  type props = {
    item: t,
    selected: bool,
    onToggle: ReactRe.event => unit,
    onDestroy: ReactRe.event => unit,
  };
  type state = {
    editing: bool
  };

  let getInitialState props => {
    editing: false
  };

  let render {props, state, updater} => {
    let { item, selected, onToggle, onDestroy } = props;
    let { editing } = state;
    let className = Utils.classNames [
      ("completed", item.completed),
      ("editing", editing),
      ("selected", selected)
    ];
    let save = updater (fun {state} text => { Js.log text; Some { editing: false } });
    let edit = updater (fun {state} e => Some { editing: true });
    let select e => Utils.gotoHash item.id;

    <li className>
      <div className="view">
        <input
          type_="checkbox"
          className="toggle"
          checked=(Js.Boolean.to_js_boolean item.completed)
          onChange=onToggle
        />

        <label onDoubleClick=edit onClick=select>
          (ReactRe.stringToElement item.title)
        </label>

        <button className="destroy" onClick=onDestroy />
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
let createElement ::item ::selected ::onToggle ::onDestroy ::children =>
  wrapProps { item, selected, onToggle, onDestroy } ::children;
