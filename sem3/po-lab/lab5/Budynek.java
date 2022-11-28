import java.time.LocalDate;
import java.time.Year;
import java.time.temporal.ChronoUnit;

public class Budynek {
    String name;
    int levels;
    LocalDate constructionYear;
    public Budynek(String name, int levels, LocalDate constructionYear) {
        this.name = name;
        this.levels = levels;
        this.constructionYear = constructionYear;
    }

    @Override
    public String toString() {
        return "Budynek{" +
                "name='" + name + '\'' +
                ", levels=" + levels +
                ", constructionYear=" + constructionYear +
                ", age=" + age() +
                '}';
    }
    long age() {
        LocalDate today = LocalDate.now();
        return ChronoUnit.YEARS.between(constructionYear, today);
    }

}
