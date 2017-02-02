
module NodoTextInput = {
  include ReactRe.Component.Stateful;
  let name = "NodoTextInput";

  type props = {
    className: string,
    placeholder: option string,
    onSave: string => unit,
    value: option string
  };
  type state = {
    value: string
  };

  let getInitialState (props: props) => {
    value: Utils.default "" props.value
  };

  let render ({props, state, updater}) => {
    let { placeholder, className, onSave } = props;
    let save = updater (fun {state} event => { onSave state.value; Some { value: "" } });
    let update = updater (fun {state} event => Some { value: ReasonJs.Document.value event##target });

    <input
      className
      placeholder=?placeholder
      onBlur=save
      onChange=update
      onKeyDown=(fun e => e##keyCode === 13 ? save e : ())
      value=state.value
      autoFocus=(Js.Boolean.to_js_boolean true)
    />
  }
};

include ReactRe.CreateComponent NodoTextInput;
let createElement ::className ::placeholder=? ::onSave ::value=? ::children =>
  wrapProps { className, placeholder, onSave, value } ::children
