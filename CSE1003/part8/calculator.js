function onCalculateClick() {
	var inputForNum1 = document.querySelector("input[name=number1]");
	var inputForNum2 = document.querySelector("input[name=number2]");

	var inputForOper = document.querySelector("select[name=operation]");
	
	var num1 = parseInt(inputForNum1.value);
	var num2 = parseInt(inputForNum2.value);

	switch(inputForOper.value) {
		case '+':
		alert(num1 + num2);
		break;
		case '-':
		alert(num1 - num2);
		break;
		case '*':
		alert(num1 * num2);
		break;
		case '/':
		alert(num1 / num2);
		break;
	}
}