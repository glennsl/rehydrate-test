
module ToggleAllCheckbox = {
  let createElement ::items ::store ::children () => {
    let checked = items |> Utils.isEvery (fun item => not Todo.(item.completed));
    let toggleAll e => Store.toggleAll store checked;

    <input
      className="toggle-all"
      type_="checkbox"
      onChange=toggleAll
      checked=(Js.Boolean.to_js_boolean checked)
    />
  }
};

let createElement ::items ::filter ::selected ::store ::children () =>
  <section className="main">
    <ToggleAllCheckbox items store />
    <NodoList items filter selected store />
  </section>
