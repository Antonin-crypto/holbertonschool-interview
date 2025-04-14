#!/usr/bin/node

const request = require("request");
const movieId = process.argv[2];

if (!movieId) {
  console.error("Usage: ./0-starwars_characters.js <Movie ID>");
  process.exit(1);
}

const apiUrl = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;

request(apiUrl, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  const filmData = JSON.parse(body);
  const characters = filmData.characters;

  characters.forEach((url) => {
    request(url, (err, res, bdy) => {
      if (!err) {
        const charData = JSON.parse(bdy);
        console.log(charData.name);
      }
    });
  });
});
