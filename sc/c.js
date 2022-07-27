let argvs = process.argv;
let fs = require("fs");
let path = require("path");
const { exec } = require("child_process");
if (argvs.length <= 2) {
  console.log("Usage: node code.js <number>");
  process.exit(1);
}

console.log("Base Dir :", process.cwd());
let baseDir = process.cwd();

let fileName = argvs.slice(2).join("");
console.log("File Name :", fileName, ". cpp");

let fileFolder = fileName.slice(0, fileName.length - 2) + "__";
console.log("File Folder :", fileFolder);

// createFolder
let folderPath = path.join(baseDir, fileFolder);
console.log("Folder Path :", folderPath);

if (!fs.existsSync(folderPath)) fs.mkdirSync(folderPath);

// createFile
let filePath = path.join(folderPath, fileName + ".cpp");
console.log("File Path :", filePath);

let preset = fs.readFileSync(path.join(__dirname, "preset"), "utf8");

if (!fs.existsSync(filePath)) fs.writeFileSync(filePath, preset);

exec("code " + filePath, (err, stdout, stderr) => {});
