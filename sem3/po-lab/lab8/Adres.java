public class Adres {
    String ulica, miasto, kodPocztowy;
    int numerDomu;

    public static String validate(String ulica, String miasto, String kodPocztowy, int numerDomu) {
        String message = "";

        if (ulica == null) {
            message += "Ulica nie moze byc nullem. ";
        }

        if (miasto == null) {
            message += "Miasto nie moze byc nullem. ";
        }

        if (kodPocztowy == null) {
            message += "Kod pocztowy nie moze byc nullem. ";
        }

        if (numerDomu <= 0) {
            message += "Numer domu nie moze byc mniejszy lub rowny 0. ";
        }

        return message;
    }

    public Adres(String ulica, String miasto, String kodPocztowy, int numerDomu) throws ExceptionAddress {
        String validateMsg = validate(ulica, miasto, kodPocztowy, numerDomu);
        if (validateMsg.length() > 0) {
            throw new ExceptionAddress(validateMsg);
        }

        this.ulica = ulica;
        this.miasto = miasto;
        this.kodPocztowy = kodPocztowy;
        this.numerDomu = numerDomu;

    }
}
