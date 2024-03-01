-- Income Tax Calculator(2016-2017) India
function calculate_income_tax_for_normal_citizen(annual_income)
    local income_tax = 0.0
    if annual_income <= 250000.0 then
        -- slab 0
        income_tax = 0.0
    elseif annual_income > 250000.0 and annual_income <= 500000.0 then
        -- slab 1
        income_tax = (annual_income - 250000.0) * 0.1
        income_tax = income_tax + 0.03 * income_tax
    elseif annual_income > 500000.0 and annual_income <= 1000000.0 then
        -- slab 2
        income_tax = 25000.0
        income_tax = income_tax + (annual_income - 500000.0) * 0.2
        income_tax = income_tax + 0.03 * income_tax
    elseif annual_income > 1000000.0 and annual_income <= 10000000.0 then
        -- slab 3
        income_tax = 125000.0
        income_tax = income_tax + (annual_income - 1000000.0) * 0.3
        income_tax = income_tax + 0.03 * income_tax
    else
        -- slab 4
        income_tax = 2825000.0
        income_tax = income_tax + (annual_income - 10000000.0) * 0.3
        income_tax = income_tax + 0.15 * income_tax
        income_tax = income_tax + 0.03 * income_tax
    end
    return income_tax
end

function calculate_income_tax_for_senior_citizen(annual_income)
    local income_tax = 0.0
    if annual_income <= 300000.0 then
        -- slab 0
        income_tax = 0.0
    elseif annual_income > 300000.0 and annual_income <= 500000.0 then
        -- slab 1
        income_tax = (annual_income - 250000.0) * 0.1
        income_tax = income_tax + 0.03 * income_tax
    elseif annual_income > 500000.0 and annual_income <= 1000000.0 then
        -- slab 2
        income_tax = 20000.0
        income_tax = income_tax + (annual_income - 500000.0) * 0.2
        income_tax = income_tax + 0.03 * income_tax
    elseif annual_income > 1000000.0 and annual_income <= 10000000.0 then
        -- slab 3
        income_tax = 120000.0
        income_tax = income_tax + (annual_income - 1000000.0) * 0.3
        income_tax = income_tax + 0.03 * income_tax
    else
        -- slab 4
        income_tax = 2820000.0
        income_tax = income_tax + (annual_income - 10000000.0) * 0.3
        income_tax = income_tax + 0.15 * income_tax
        income_tax = income_tax + 0.03 * income_tax
    end
    return income_tax
end

function calculate_income_tax_for_super_senior_citizen(annual_income)
    local income_tax = 0.0
    if annual_income <= 500000.0 then
        -- slab 0
        income_tax = 0.0
    elseif annual_income > 500000.0 and annual_income <= 1000000.0 then
        -- slab 1
        income_tax = (annual_income - 500000.0) * 0.2
        income_tax = income_tax + 0.03 * income_tax
    elseif annual_income > 1000000.0 and annual_income <= 10000000.0 then
        -- slab 2
        income_tax = 100000.0
        income_tax = income_tax + (annual_income - 1000000.0) * 0.3
        income_tax = income_tax + 0.03 * income_tax
    else
        -- slab 3
        income_tax = 2800000.0
        income_tax = income_tax + (annual_income - 10000000.0) * 0.3
        income_tax = income_tax + 0.15 * income_tax
        income_tax = income_tax + 0.03 * income_tax
    end
    return income_tax
end