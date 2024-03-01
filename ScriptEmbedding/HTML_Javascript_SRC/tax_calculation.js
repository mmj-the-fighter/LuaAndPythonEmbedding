function response(frm)
{
    var annualIncome = parseFloat(frm.elements.annualIncome.value);
    var citizenType = frm.elements.citizenType;
    var citizenTypeStr;
    
    for(var i = 0; i < citizenType.length; i++) {
        if (citizenType[i].checked) {
            citizenTypeStr = citizenType[i].value;
            break;
        }
    }
    
    switch(citizenTypeStr)
    {
        case "normal": 
            frm.elements.incomeTax.value = calculateIncomeTaxForNormalCitizen(annualIncome);
            break;
        case "senior": 
            frm.elements.incomeTax.value = calculateIncomeTaxForSeniorCitizen(annualIncome);
            break;
        case "supersenior": 
            frm.elements.incomeTax.value = calculateIncomeTaxForSuperSeniorCitizen(annualIncome);
            break;
    }
    
}

function calculateIncomeTaxForNormalCitizen(annualIncome)
{
	var incomeTax = 0.0;
	if (annualIncome <= 250000.0)
	{
		//slab 0
		incomeTax = 0.0;
	}
	else if (annualIncome > 250000.0 && annualIncome <= 500000.0){
		//slab 1
		incomeTax = (annualIncome - 250000.0)*0.1;
		incomeTax += 0.03 * incomeTax;
	}
	else if (annualIncome > 500000.0 && annualIncome <= 1000000.0){
		//slab 2
		incomeTax = 25000.0;
		incomeTax += (annualIncome - 500000.0)*0.2;
		incomeTax += 0.03 * incomeTax;
	}
	else if (annualIncome > 1000000.0 && annualIncome <= 10000000.0){
		//slab 3
		incomeTax = 125000.0;
		incomeTax += (annualIncome - 1000000.0)*0.3;
		incomeTax += 0.03 * incomeTax;
	}
	else{
		//slab 4
		incomeTax = 2825000.0;
		incomeTax += (annualIncome - 10000000.0)*0.3;
		incomeTax += 0.15 * incomeTax;
		incomeTax += 0.03 * incomeTax;
	}
	return incomeTax;
}

function calculateIncomeTaxForSeniorCitizen(annualIncome)
{
	var incomeTax = 0.0;
	if (annualIncome <= 300000.0)
	{
		//slab 0
		incomeTax = 0.0;
	}
	else if (annualIncome > 300000.0 && annualIncome <= 500000.0){
		//slab 1
		incomeTax = (annualIncome - 250000.0)*0.1;
		incomeTax += 0.03 * incomeTax;
	}
	else if (annualIncome > 500000.0 && annualIncome <= 1000000.0){
		//slab 2
		incomeTax = 20000.0;
		incomeTax += (annualIncome - 500000.0)*0.2;
		incomeTax += 0.03 * incomeTax;
	}
	else if (annualIncome > 1000000.0 && annualIncome <= 10000000.0){
		//slab 3
		incomeTax = 120000.0;
		incomeTax += (annualIncome - 1000000.0)*0.3;
		incomeTax += 0.03 * incomeTax;
	}
	else{
		//slab 4
		incomeTax = 2820000.0;
		incomeTax += (annualIncome - 10000000.0)*0.3;
		incomeTax += 0.15 * incomeTax;
		incomeTax += 0.03 * incomeTax;
	}
	return incomeTax;
}

function calculateIncomeTaxForSuperSeniorCitizen(annualIncome)
{
	var incomeTax = 0.0;
	if (annualIncome <= 500000.0)
	{
		//slab 0
		incomeTax = 0.0;
	}
	else if (annualIncome > 500000.0 && annualIncome <= 1000000.0){
		//slab 1
		incomeTax = (annualIncome - 500000.0)*0.2;
		incomeTax += 0.03 * incomeTax;
	}
	else if (annualIncome > 1000000.0 && annualIncome <= 10000000.0){
		//slab 2
		incomeTax = 100000.0;
		incomeTax += (annualIncome - 1000000.0)*0.3;
		incomeTax += 0.03 * incomeTax;
	}
	else{
		//slab 3
		incomeTax = 2800000.0;
		incomeTax += (annualIncome - 10000000.0)*0.3;
		incomeTax += 0.15 * incomeTax;
		incomeTax += 0.03 * incomeTax;
	}
	return incomeTax;
}