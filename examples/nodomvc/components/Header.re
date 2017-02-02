
let createElement ::store ::children () => {
  let save text =>
    if (String.trim text !== "") {
      Store.add store text;
    };

  <header className="header">
    <h1> (ReactRe.stringToElement "todos") </h1>
    <NodoTextInput
      className="new-todo"
      placeholder="What needs to be done?"
      onSave=save
    />
  </header>
};
