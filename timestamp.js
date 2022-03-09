/* Check to see if this code has been run before
and print last run time if it has. Will throw
an error the first time it is run */
const fs = require('fs');
const PATH = `${__dirname}/last_run.json`;
fs.readFile(PATH, 'utf-8', (err, data) => {
  if (err) {console.log('Has not been run before. Run code again.');};
  const last_run = JSON.parse(data);
  console.log(`Last run on ${last_run['last_run']}`);
});

// Get current date and time
let currentDate = new Date();
let month = currentDate.getMonth() + 1;  // getMonth uses 0-11 format
let day = currentDate.getDate();
let year = currentDate.getFullYear();
let hour = currentDate.getHours();
// getMinutes doesn't have a leading 0 on numbers 0-9
function returnMinutes() {
  if (currentDate.getMinutes() < 10) {
    return `0${currentDate.getMinutes()}`
  } else {
    return currentDate.getMinutes()
  }
};
let minute = returnMinutes();

// write date and time to last_run.json
let timestamp = `${month}/${day}/${year} ${hour}:${minute}`;
let timestamp_obj = {
  'last_run': timestamp,
};
let timestamp_str = JSON.stringify(timestamp_obj);
fs.writeFile(PATH, timestamp_str, (err) => {
    if(err) console.log(err);
});
