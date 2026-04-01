CREATE DEFINER=`root`@`localhost` PROCEDURE `Insertproduct`(IN barcode INT, name VARCHAR(50), price FLOAT, quantityInStock INT)
BEGIN
	IF price > 0 AND quantityInStock >= 0 
    THEN 
		INSERT INTO Product VALUES (barcode, name, price, quantityInStock);
    END IF;
END