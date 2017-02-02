type t = {
  id: string,
  title: string,
  completed: bool,
  created: ReasonJs.Date.t
};

let newId () => [%bs.raw {|'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, (c) => (c === 'x' ? Math.random()*16|0 : (((Math.random()*16|0)&0x3)|0x8)).toString(16))|}];

let make title => {
  id: newId (),
  title,
  completed: false,
  created: ReasonJs.Date.make ()
};
