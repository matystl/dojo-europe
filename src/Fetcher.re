type marker = {
  username: string,
  location: (float, float),
};

module Data = {
  [@bs.deriving abstract]
  type t = {
    username: string,
    location: (float, float),
  };
};

type response1;
type promise('a);
[@bs.send] external json : response1 => 'a = "";

[@bs.deriving abstract]
type request = {
  [@bs.as "method"]
  method_: string,
  body: string,
};

[@bs.val] external fetchGet : string => promise(response1) = "fetch";

[@bs.val] external fetchPost : (string, request) => unit = "fetch";
let fetchPost = (~url, ~body) =>
  fetchPost(url, request(~method_="POST", ~body));

[@bs.send]
external then1 : (promise(response1), response1 => 'a) => promise('a) =
  "then";

[@bs.send]
external then2 : (promise(array(Data.t)), array(Data.t) => unit) => unit =
  "then";

let convertToRecord: array(Data.t) => array(marker) =
  dataArray =>
    Array.map(
      data => {
        username: data |. Data.username,
        location: data |. Data.location,
      },
      dataArray,
    );

let fetchGet = (~url, ~cb) =>
  then2(then1(fetchGet(url), json), rawData =>
    cb(convertToRecord(rawData))
  );