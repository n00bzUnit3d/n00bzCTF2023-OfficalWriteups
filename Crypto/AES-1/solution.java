import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.PBEKeySpec;
import javax.crypto.spec.SecretKeySpec;
import java.nio.charset.StandardCharsets;
import java.security.spec.KeySpec;
import java.util.Base64;

public class Main {
    private static final String AES_ALGORITHM = "AES";
    private static final String PBKDF2_ALGORITHM = "PBKDF2WithHmacSHA256";
    private static final int ITERATIONS = 10000;
    private static final int KEY_SIZE = 256;

    private static SecretKey generateKey(String password, byte[] salt) throws Exception {
        KeySpec spec = new PBEKeySpec(password.toCharArray(), salt, ITERATIONS, KEY_SIZE);
        SecretKeyFactory factory = SecretKeyFactory.getInstance(PBKDF2_ALGORITHM);
        SecretKey tmp = factory.generateSecret(spec);
        return new SecretKeySpec(tmp.getEncoded(), AES_ALGORITHM);
    }

    private static String decrypt(String encryptedText, SecretKey key) throws Exception {
        Cipher cipher = Cipher.getInstance(AES_ALGORITHM);
        cipher.init(Cipher.DECRYPT_MODE, key);
        byte[] encryptedBytes = Base64.getDecoder().decode(encryptedText);
        byte[] decryptedBytes = cipher.doFinal(encryptedBytes);
        return new String(decryptedBytes, StandardCharsets.UTF_8);
    }

    public static void main(String[] args) {
        String encryptedFlag = "FOqxc90aMQZydCQb2MUm5tj4kRIxxVeCDWzAANfOrr8JItHYneUHhSV0awvQIo/8E1LtfYm/+VVWz0PDK6MXp38BWHoFDorhdS44DzYj9CQ=";
        String password = "aesiseasy";
        byte[] salt = "saltval".getBytes(StandardCharsets.UTF_8);

        try {
            SecretKey key = generateKey(password, salt);
            String decryptedFlag = decrypt(encryptedFlag, key);
            System.out.println("Decrypted Flag: " + decryptedFlag);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
