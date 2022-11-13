import ExifParser from 'exif-parser';
import {promises as fs} from 'fs';

(async () => {
    const imgbuffer = await fs.readFile(process.argv[2]);
    const parser = ExifParser.create(imgbuffer);
    parser.enableBinaryFields(true);
    parser.enableTagNames(true);
    parser.enableImageSize(true);
    parser.enableReturnTags(true);

    const img = parser.parse();

    const data = img.tags;
    const properties = [
        {properties: ['Make', 'Model', 'Software'], name: 'Device'},
        'ISO',
        {properties: ['GPSLatitude', 'GPSLatitudeRef', 'GPSLongitude', 'GPSLongitudeRef'], name: 'Location'},
        'LensModel',
        'BrightnessValue',
        {properties: ['ExifImageHeight'], name: 'Height'},
        {properties: ['ExifImageWidth'], name: 'Width'},
        'Flash',
        {properties: ['XResolution', 'YResolution'], name: 'Resolution'},
    ];
    for (const prop of properties) {
        console.log(typeof prop === 'string' ? `${prop}: ${data[prop]}` : `${prop.name}: ${prop.properties.map((e) => data[e]).join(' ')}`);
    }
    console.log('Created at', new Date(data.CreateDate));
})();
