## Here’s an explanation and configuration examples for **OSPF**, **EIGRP**, and **HSRP** in Cisco IOS.

## **1. OSPF (Open Shortest Path First)**

OSPF is a **link-state routing protocol** that uses Dijkstra's algorithm to calculate the shortest path. It supports **VLSM**, **CIDR**, and converges quickly.

### **Basic OSPF Configuration Example**

```bash
Router(config)# router ospf 1            # Enable OSPF process ID 1
Router(config-router)# network 192.168.1.0 0.0.0.255 area 0  # Advertise network in Area 0
Router(config-router)# network 10.0.0.0 0.255.255.255 area 0
Router(config-router)# passive-interface GigabitEthernet0/1  # Prevent OSPF updates on this interface
```

### **Verification Commands**

```bash
show ip ospf neighbor      # Check OSPF neighbors
show ip ospf database      # View OSPF LSDB
show ip route ospf         # Check OSPF routes
```

---

## **2. EIGRP (Enhanced Interior Gateway Routing Protocol)**

EIGRP is a **Cisco-proprietary advanced distance-vector protocol** that uses **DUAL** for fast convergence and supports **unequal-cost load balancing**.

### **Basic EIGRP Configuration (Autonomous System 100)**

```bash
Router(config)# router eigrp 100          # Enable EIGRP AS 100
Router(config-router)# network 192.168.1.0
Router(config-router)# network 10.0.0.0
Router(config-router)# no auto-summary    # Disable automatic summarization (if needed)
```

### **Verification Commands**

```bash
show ip eigrp neighbors    # Check EIGRP neighbors
show ip eigrp topology     # View EIGRP topology table
show ip route eigrp        # Check EIGRP routes
```

---

## **3. HSRP (Hot Standby Router Protocol)**

HSRP is a **Cisco-proprietary FHRP (First Hop Redundancy Protocol)** that provides **gateway redundancy** for hosts on a LAN.

### **Basic HSRP Configuration (Virtual IP: 192.168.1.1)**

```bash
Router(config)# interface GigabitEthernet0/1
Router(config-if)# ip address 192.168.1.2 255.255.255.0
Router(config-if)# standby 1 ip 192.168.1.1    # HSRP group 1 with VIP
Router(config-if)# standby 1 priority 110       # Set priority (default: 100)
Router(config-if)# standby 1 preempt             # Allow preemption
Router(config-if)# standby 1 track GigabitEthernet0/2  # Track interface for failover
```

### **Verification Commands**

```bash
show standby brief      # Check HSRP status
show standby           # Detailed HSRP info
```

---

### **Summary of Key Differences**

| Feature       | OSPF                       | EIGRP                            | HSRP                       |
| ------------- | -------------------------- | -------------------------------- | -------------------------- |
| **Type**      | Link-state (Open Standard) | Advanced Distance-Vector (Cisco) | Gateway Redundancy (Cisco) |
| **Algorithm** | Dijkstra (SPF)             | DUAL                             | Active/Standby Election    |
| **Use Case**  | Enterprise networks        | Cisco environments               | Default gateway redundancy |

Would you like more advanced configurations (like authentication, route summarization, or tuning timers)? Let me know!
