function paddedStr = num2padstr(number, pad)
    str = num2str(number);  % Convert the number to a string
    numDigits = numel(str); % Get the number of digits in the string

    if numDigits >= pad
        paddedStr = str;    % No padding needed
    else
        numZeros = pad - numDigits;
        zerosStr = repmat('0', 1, numZeros); % Create a string of zeros
        paddedStr = [zerosStr str];          % Concatenate zeros and number
    end
end