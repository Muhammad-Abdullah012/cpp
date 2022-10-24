const fs = require('fs');
const path = require('path');
fs.readdir(__dirname, (err, files) => {
    files.forEach((filename) => {
        let extension = filename.split('.').pop();
        if(extension === 'cpp') {
            console.log(filename.split('.').shift());
            const WriteStream = fs.createWriteStream(path.join(__dirname, "txt", filename.split('.').shift()+'.txt'), {
                flags: 'w'
            })
            const ReadStream = fs.createReadStream(path.join(__dirname, filename)).pipe(WriteStream);
            
        }
    })
})

