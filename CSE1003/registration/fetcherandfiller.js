// FETCHER
var dataStore = [];
document.querySelectorAll('input').forEach((input) => {
    if(input.getAttribute('type') !== 'radio' || input.checked === true) {
        dataStore.push({
            name: input.getAttribute('name'),
            type: input.getAttribute('type'),
            value: input.value
        });
    }
 });
document.querySelectorAll('select').forEach((select) => { dataStore.push({name: select.getAttribute('name'), type: "select", value: select.value }); });

// FILLER
var dataStoreAsJSON = "[{\"name\":\"name\",\"type\":\"text\",\"value\":\"Swarup Ghosh\"},{\"name\":\"fathername\",\"type\":\"text\",\"value\":\"SN Ghosh\"},{\"name\":\"fatheroccupation\",\"type\":\"text\",\"value\":\"Business\"},{\"name\":\"fathermobile\",\"type\":\"tel\",\"value\":\"+917044093762\"},{\"name\":\"fatheremail\",\"type\":\"email\",\"value\":\"essenghosh@gmail.com\"},{\"name\":\"mothername\",\"type\":\"text\",\"value\":\"Soma Ghosh\"},{\"name\":\"motheroccupation\",\"type\":\"text\",\"value\":\"Business\"},{\"name\":\"mothermobile\",\"type\":\"tel\",\"value\":\"+919748905620\"},{\"name\":\"motheremail\",\"type\":\"email\",\"value\":\"somaghoshnt@gmail.com\"},{\"name\":\"enrolmentnumber\",\"type\":\"number\",\"value\":\"170020203040\"},{\"name\":\"programme\",\"type\":\"text\",\"value\":\"B.Tech (CSE)\"},{\"name\":\"domicile\",\"type\":\"radio\",\"value\":\"other\"},{\"name\":\"hostel\",\"type\":\"radio\",\"value\":\"Hosteller\"},{\"name\":\"coursecodes[]\",\"type\":\"text\",\"value\":\"CSE1003\"},{\"name\":\"coursenames[]\",\"type\":\"text\",\"value\":\"Web Programming through PHP and HTML\"},{\"name\":\"coursecodes[]\",\"type\":\"text\",\"value\":\"MAT1702\"},{\"name\":\"coursenames[]\",\"type\":\"text\",\"value\":\"Matrices and Differential Equations\"},{\"name\":\"coursecodes[]\",\"type\":\"text\",\"value\":\"ENV1701\"},{\"name\":\"coursenames[]\",\"type\":\"text\",\"value\":\"Environmental Studies\"},{\"name\":\"coursecodes[]\",\"type\":\"text\",\"value\":\"PHY1003\"},{\"name\":\"coursenames[]\",\"type\":\"text\",\"value\":\"Engineering Physics\"},{\"name\":\"coursecodes[]\",\"type\":\"text\",\"value\":\"PHL1741\"},{\"name\":\"coursenames[]\",\"type\":\"text\",\"value\":\"Introduction to Critical Thinking\"},{\"name\":\"coursecodes[]\",\"type\":\"text\",\"value\":\"ELE1001\"},{\"name\":\"coursenames[]\",\"type\":\"text\",\"value\":\"Fundamentals of Electrical and Electronics Engineering\"},{\"name\":\"coursecodes[]\",\"type\":\"text\",\"value\":\"IPT1602\"},{\"name\":\"coursenames[]\",\"type\":\"text\",\"value\":\"Inter Disciplinary Project II\"},{\"name\":\"coursecodes[]\",\"type\":\"text\",\"value\":\"CSE1003L\"},{\"name\":\"coursenames[]\",\"type\":\"text\",\"value\":\"Web Programming through PHP and HTML Lab\"},{\"name\":\"coursecodes[]\",\"type\":\"text\",\"value\":\"PHY1003L\"},{\"name\":\"coursenames[]\",\"type\":\"text\",\"value\":\"Engineering Physics Lab\"},{\"name\":\"coursecodes[]\",\"type\":\"text\",\"value\":\"ELE1001L\"},{\"name\":\"coursenames[]\",\"type\":\"text\",\"value\":\"Fundamentals of Electrical and Electronics Engineering Lab\"},{\"name\":\"date\",\"type\":\"datetime\",\"value\":\"2018-01-15\"},{\"name\":\"feereceipts\",\"type\":\"radio\",\"value\":\"yes\"},{\"name\":\"address\",\"type\":\"text\",\"value\":\"HIG-2, Block-1, Flat-7C, Greenwood Park, Newtown, Kolkata-700156\"},{\"name\":\"emailaddress\",\"type\":\"text\",\"value\":\"contact@swghosh.cu.cc\"},{\"name\":\"mobile\",\"type\":\"text\",\"value\":\"+918961517827\"},{\"name\":\"facultyname\",\"type\":\"text\",\"value\":\"Shipra Kataria\"},{\"name\":null,\"type\":\"submit\",\"value\":\"Register\"},{\"name\":\"school\",\"type\":\"select\",\"value\":\"som\"},{\"name\":\"semester\",\"type\":\"select\",\"value\":\"2\"}]";
var dataStore = JSON.parse(dataStoreAsJSON);
// input radio filling
dataStore.filter((val) => {
    return val.type === 'radio'
}).forEach((val) => {
    document.getElementsByName(val.name).forEach((node) => {
        if(node.value === val.value) node.checked = true;
    });
});
// input filling
dataStore.filter((val) => {
    return val.type !== 'radio' && val.type !== 'select'
}).filter((val) => {
    return val.name !== null && val.name.endsWith('[]') === false
}).forEach((val) => {
    document.getElementsByName(val.name).forEach((node) => {
        node.value = val.value;
    });
});
// input array filling
var arrayData = dataStore.filter((val) => {
    return val.type !== 'radio' && val.type !== 'select'
}).filter((val) => {
    return val.name !== null && val.name.endsWith('[]')
});
for(var index = 0; index < arrayData.length; index+=2) {
    document.getElementsByName(arrayData[index].name)[index / 2].value = arrayData[index].value;
    document.getElementsByName(arrayData[index + 1].name)[index / 2].value = arrayData[index + 1].value;
}
