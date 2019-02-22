import com.google.gson.Gson;

class Sample {
    float value;
    String unit;

    Sample(float value, String unit) {
        this.value = value;
        this.unit = unit;
    }
}

public class GsonTest {
    public static void main(String[] args) {
        Sample sample = new Sample(130.02f, "cm");
        Gson gson = new Gson();
        System.out.println(gson.toJson(sample));
    }
}
