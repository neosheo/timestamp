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
currentDate = new Date();
month = currentDate.getMonth() + 1;  // getMonth uses 0-11 format
day = currentDate.getDate();
year = currentDate.getFullYear();
hour = currentDate.getHours();
// getMinutes doesn't have a leading 0 on numbers 0-9
minute = () => {
  if (currentDate.getMinutes() < 10) {
    return `0${currentDate.getMinutes()}`
  } else {
    return currentDate.getMinutes()
  }
};

// write date and time to last_run.json
timestamp = `${month}/${day}/${year} ${hour}:${minute()}`;
timestamp_obj = {
  'last_run': timestamp,
};
timestamp_str = JSON.stringify(timestamp_obj);
fs.writeFile(PATH, timestamp_str, (err) => {
    if(err) console.log(err);
});
