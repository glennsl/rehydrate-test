type t =
| All
| Active
| Completed;

let list = [All, Active, Completed];

let toString = fun
| All => "All"
| Active => "Active"
| Completed => "Completed";
