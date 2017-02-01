
module NodoTextInput = {
  include ReactRe.Component.Stateful;
  let name = "NodoTextInput";

  type props = {
    className: string,
    placeholder: string,
    onSave: string => unit
  };
  type state = {
    value: string
  };

  let getInitialState props => {
    value: ""
  };

  let render ({props, state, updater}) => {
    let { placeholder, className, onSave } = props;
    let save = updater (fun {state} event => { onSave state.value; Some { value: "" } });
    let update = updater (fun {state} event => Some { value: ReasonJs.Document.value event##target });

    <input
      className
      placeholder
      onBlur=save
      onChange=update
      onKeyDown=(fun e => e##keyCode === 13 ? save e : ())
      value=state.value
      autoFocus=(Js.Boolean.to_js_boolean true) />
  }
};

include ReactRe.CreateComponent NodoTextInput;
let createElement ::className ::placeholder ::onSave ::children =>
  wrapProps {className, placeholder, onSave} ::children
