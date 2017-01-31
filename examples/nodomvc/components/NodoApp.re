module NodoApp = {
  include ReactRe.Component;
  let name = "NodoPage";

  type props = {todos: list NodoItem.item};

  let render {props, updater} =>
    <div>
      <header className="header">
        <h1> (ReactRe.stringToElement "todos") </h1>
      </header>
      <section className="main">
        <NodoList items=props.todos />
      </section>
      <NodoFooter items=props.todos onClearCompleted=(fun e => ()) />
    </div>;
};

include ReactRe.CreateComponent NodoApp;

let createElement ::todos ::children => wrapProps { todos: todos } ::children;
