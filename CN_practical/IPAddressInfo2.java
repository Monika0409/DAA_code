import java.net.InetAddress;
import java.net.UnknownHostException;
import java.io.IOException;
import java.util.Scanner;

public class IPAddressInfo2 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the IP Address: ");
        String ipAddress = scanner.nextLine();

        try {
            InetAddress inetAddress = InetAddress.getByName(ipAddress);

            // Determine if the IP address is reserved, public, or private
            String ipType = getIPType(inetAddress);

            // Determine the IP class
            String ipClass = getIPClass(inetAddress);

            // Determine the default mask
            String defaultMask = getDefaultMask(inetAddress);

            // Determine the network address and block
            String[] blockInfo = getBlockInfo(inetAddress);

            // Print the information
            System.out.println("Given IP is: " + ipType);
            System.out.println("This IP Address Belongs to Class: " + ipClass);
            System.out.println("Default Mask: " + defaultMask);
            System.out.println("Block: " + blockInfo[0]);
            System.out.println("First IP: " + blockInfo[1]);
            System.out.println("Last IP: " + blockInfo[2]);
            System.out.println("Network Address: " + blockInfo[3]);

            // For Classless Addressing
            int cidrValue = Integer.parseInt(blockInfo[0].split("/")[1]);
            String maskInDecimal = getMaskInDecimal(cidrValue);
            int numAddresses = (int) Math.pow(2, 32 - cidrValue);
            String firstIP = blockInfo[1];
            String lastIP = blockInfo[2];
            String networkAddress = blockInfo[3];

            System.out.println("\nFor Classless Addressing:");
            System.out.println("/ Value: " + cidrValue);
            System.out.println("Mask in Decimal: " + maskInDecimal);
            System.out.println("No of IP Addresses in Block: " + numAddresses);
            System.out.println("First IP: " + firstIP);
            System.out.println("Last IP: " + lastIP);
            System.out.println("Network Address: " + networkAddress);
        } catch (UnknownHostException e) {
            System.out.println("Invalid IP Address.");
        } 
        scanner.close();
    }

    private static String getIPType(InetAddress inetAddress) {
        if (inetAddress.isAnyLocalAddress() || inetAddress.isLoopbackAddress() || inetAddress.isLinkLocalAddress()
                || inetAddress.isSiteLocalAddress() || inetAddress.isMulticastAddress()) {
            return "Reserved";
        } else if (!isReachable(inetAddress, 1000)) {
            return "Public";
        } else {
            return "Private";
        }
    }

    private static boolean isReachable(InetAddress inetAddress, int timeout) {
        try {
            return inetAddress.isReachable(timeout);
        } catch (IOException e) {
            // Handle the IOException
            return false;
        }
    }

    private static String getIPClass(InetAddress inetAddress) {
        byte[] addressBytes = inetAddress.getAddress();
        int firstOctet = addressBytes[0] & 0xFF; // Convert byte to unsigned int
        if (firstOctet >= 0 && firstOctet <= 127) {
            return "A";
        } else if (firstOctet >= 128 && firstOctet <= 191) {
            return "B";
        } else if (firstOctet >= 192 && firstOctet <= 223) {
            return "C";
        } else if (firstOctet >= 224 && firstOctet <= 239) {
            return "D";
        } else {
            return "E";
        }
    }

    private static String getDefaultMask(InetAddress inetAddress) {
        byte[] addressBytes = inetAddress.getAddress();
        int firstOctet = addressBytes[0] & 0xFF; // Convert byte to unsigned int
        if (firstOctet >= 0 && firstOctet <= 127) {
            return "255.0.0.0";
        } else if (firstOctet >= 128 && firstOctet <= 191) {
            return "255.255.0.0";
        } else if (firstOctet >= 192 && firstOctet <= 223) {
            return "255.255.255.0";
        } else {
            return "Not Applicable";
        }
    }

    private static String[] getBlockInfo(InetAddress inetAddress) {
        byte[] addressBytes = inetAddress.getAddress();
        int numAddresses = (int) Math.pow(2, 32 - addressBytes.length);

        String ipAddress = inetAddress.getHostAddress();
        String[] parts = ipAddress.split("\\.");
        int[] octets = new int[4];
        for (int i = 0; i < parts.length; i++) {
            octets[i] = Integer.parseInt(parts[i]);
        }

        StringBuilder block = new StringBuilder();
        block.append(ipAddress).append("/").append(numAddresses);
        
        octets[3] += 1; // Increment last octet by 1
        String firstIP = octets[0] + "." + octets[1] + "." + octets[2] + "." + octets[3];

        octets[3] += numAddresses - 2; // Increment last octet by numAddresses - 2
        String lastIP = octets[0] + "." + octets[1] + "." + octets[2] + "." + octets[3];

        String networkAddress = parts[0] + "." + parts[1] + "." + parts[2] + ".0";

        return new String[]{block.toString(), firstIP, lastIP, networkAddress};
    }

    private static String getMaskInDecimal(int cidrValue) {
        StringBuilder mask = new StringBuilder();
        for (int i = 0; i < 4; i++) {
            int octet = cidrValue >= 8 ? 255 : (256 - (int) Math.pow(2, 8 - cidrValue)) % 256;
            mask.append(octet);
            if (i < 3) {
                mask.append(".");
            }
            cidrValue = Math.max(0, cidrValue - 8);
        }
        return mask.toString();
    }
}
