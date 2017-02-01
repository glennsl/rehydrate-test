
let createElement ::children => fun () =>
  <header className="header">
    <h1> (ReactRe.stringToElement "todos") </h1>
    <NodoTextInput className="new-todo" placeholder="What needs to be done?" onSave=(fun text => Js.log text) />
  </header>
