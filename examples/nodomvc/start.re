open Components;

let todos: list NodoItem.item = [{
  id: "",
  title: "Item 1",
  completed: false
}, {
  id: "",
  title: "Item 2",
  completed: true
}];

ReactDOMRe.render <NodoApp todos=todos /> (ReasonJs.Document.getElementById "nodoapp");
